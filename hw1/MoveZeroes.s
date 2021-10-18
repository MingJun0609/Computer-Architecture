.data
nums:		.word 0, 1, 0, 3, 12
numsSize:	.word 5
space:		.string  "  "
before:		.string  "Before move zeroes = "
after:		.string  "After  move zeroes = "
nextline:	.string  "\n"

.text
main:
		la	s0, nums		# s0 = nums[0]
		lw	s1, numsSize	# s1 = numsSize
		la	a0, before		# pointer to string
		li	a7, 4			# print .string
		ecall
		jal		print		# print nums before move
		la		a0, nextline
		li		a7, 4
		ecall

		jal		moveZeroes	# moveZeroes (leaf procedure)

		la		a0, after
		li		a7, 4
		ecall
		jal		print		# print nums after move

		li		a7, 10		# exit
		ecall

moveZeroes:
		addi	a1, zero, 0		# a1: start = 0
		addi	t0, zero, -1	# t0: i = -1
	Loop:
		addi	t0, t0, 1		# i += 1
		bge		t0, s1, While	# i >= len -> While: 
		slli	t1, t0, 2		# t1: i << 2
		add		t1, t1, s0		# t1 = nums[i]
		lw		t1, 0(t1)
		beq		t1, zero, Loop	# nums[i] == 0 -> Loop:
		slli	t2, a1, 2		# else, t2: start << 2
		add		t2, t2, s0		# t2 = nums[start]
		sw		t1, 0(t2)		# nums[start] = nums[i]
		addi	a1, a1, 1		# start += 1
		j		Loop
	While:
		bge		a1, s1, Exit	# start >= numsSize : Exit
		slli	t2, a1, 2		# t2: start << 2
		add		t2, t2, s0		# t2: nums[start]
		sw		zero, 0(t2)		# nums[start] = 0
		addi	a1, a1, 1		# start += 1
		j		While
	Exit:
		jr       ra

print:
		addi	t0, zero, 0		# i = 0
	loopi:
		bge		t0, s1, end		# i >= numsSize, end
		slli	t1, t0, 2		# t1: i << 2
		add		t1, t1, s0		# t1: nums[i]
		lw		a0, 0(t1)
		li		a7, 1			# print int
		ecall
		la		a0, space
		li		a7, 4
		ecall
		addi	t0, t0, 1		# i += 1
		j		loopi
	end:
		jr		ra