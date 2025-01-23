dateString = input("(dd/mm/yyyy): ")
args = dateString.split('/')

day = args[0] if len(args) > 0 and args[0] else 'Unknown'
month = args[1] if len(args) > 1 and args[1] else 'Unknown'
year = args[2] if len(args) > 2 and args[2] else 'Unknown'

print(f'Ngày: {day}, Tháng: {month}, Năm: {year}')

