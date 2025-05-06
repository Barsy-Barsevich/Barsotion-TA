# This code is for adding 'mm' to Mid X & Mid Y for GNG PNP format
#
# How to format PNP as GNG requires?
# (1) rename columns:
#     Ref -> Designator
#     Rot -> Rotation
#     PosX -> Mid X
#     PosY -> Mid Y
#     Side -> Layer
#     Val -> Comment
# (2) set columns in right order:
#     Designator, Package, Mid X, Mid Y, Rotation, Layer, Comment
# (3) in the Layer column: replace 'top' to 'T', 'bottom' to 'B'
# (4) use this program to add 'mm' in Mid X & Mid Y columns

file_contents = ''
column_designators = ''
with open('ThetaAnomalain-all-pos.csv', 'r') as f:
    column_designators = f.readline()
    file_contents = f.read()

f_arr = file_contents.split('\n')

with open('Barsotion-TA_v1.6_PNP_GNG_format.csv', 'w') as f:
    f.write(column_designators)
    for s in f_arr:
        if len(s) == 0:
            continue
        idx = 0
        print(s)
        cnt = 0
        while cnt < 3:
            #print(idx)
            if s[idx] == ',':
                cnt += 1
            idx += 1
        s = s[:idx-1] + 'mm' + s[idx-1:]
        cnt = 0
        while cnt < 2:
            if s[idx] == ',':
                cnt += 1
            idx += 1
        s = s[:idx-1] + 'mm' + s[idx-1:]

        f.write(s)
        f.write('\n')