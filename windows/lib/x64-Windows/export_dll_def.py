import ida_hexrays
import idc
def get_fun_def(addr):
    fun_str = str(ida_hexrays.decompile(addr))
    return fun_str[:fun_str.find('\n')]


def get_export_addrs(start_addr, end_addr, base):
    ret = []
    now = start_addr
    while now < end_addr:
        ret.append(idc.Dword(now) + base)
        now += 4
    return ret
def export_data():
    addr_list = get_export_addrs(0x1800102F8, 0x18001071C, 0x180000000)
    name_addr_list = get_export_addrs(0x18001071C, 0x180010B40, 0x180000000)

    fp = open('trch-1.h', 'w')
    name_table_file = open('trch-1-tbable.txt', 'w')
    for i in range(len(addr_list)):
        old_name = idc.GetFunctionName(addr_list[i])
        new_name = idc.GetString(name_addr_list[i])
        print('i={} funaddr={} oldname={} newname={}'.format(i, hex(addr_list[i]), old_name, new_name))
        fun_def_str = get_fun_def(addr_list[i]) + ';\n'
        if old_name != new_name:
            s = '{}:{}\n'.format(old_name, new_name)
            fun_def_str = fun_def_str.replace(old_name, new_name)
            name_table_file.write(s)
        fp.write(fun_def_str)
    fp.close()
    name_table_file.close()
