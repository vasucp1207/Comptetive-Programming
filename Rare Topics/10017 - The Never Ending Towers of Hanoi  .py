def TOH(disc, src, dest, imd):
	
	if disc == 1:
		print(1, " ", src, " ", dest)
		return
		
	TOH(disc - 1, src, imd, dest)
	print(disc, " ", src, " ", dest)
	TOH(disc - 1, imd, dest, src)		
	
n = 3
TOH(n, 'A', 'C', 'B')
