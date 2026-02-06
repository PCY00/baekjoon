x, y = map(int, input().split())

def my_pos(n):
    idx = n-1
    row = idx % 4
    col = idx // 4

    return row, col

row_x, col_x = my_pos(x)
row_y, col_y = my_pos(y)

print(abs(row_x - row_y) + abs(col_x - col_y))