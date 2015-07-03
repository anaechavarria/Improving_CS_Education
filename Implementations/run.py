from subprocess import *
import sys

def get_output(cmnd):
	try:
	    cmnd_output = check_output(cmnd, stderr=STDOUT, shell=True);                         
	except CalledProcessError as exc:                                                                                                   
	    print("Status : FAIL", exc.returncode, exc.output)
	else:                                                                                                   
	    return cmnd_output



get_output("g++ naive.cpp -O0 -o naive")
get_output("g++ dp.cpp -O0 -o dp")

# Run and time the real program with file t.n.4.in
# Where t is the max value in the array and n is the
# number of input elements.
def run_program(prog):
	o = get_output("time ./%s < %s.%s.4.in" % (prog, t, n))
	ol = o.split('\n')
	op = long(ol[0])
	time = 0

	for l in ol:
		if l.startswith('real'):
			nt = float(l.split('m')[1].split('s')[0])
			time = nt
			break
	return op, time


for t in range(1, 7):
	t = 10 ** t # The value of the maximum element in the array.
	for n in range(2, 6): # The number of elements in the array.
		n = 10 ** n
		dp_ops = 0.0    # Average number of operations of DP algorithm.
		dp_times = 0.0  # Average running times of the DP algorithm.
		na_ops = 0.0    # Average number of operations of naive algorithm.
		na_times = 0.0  # Average running time of naive algorithm.
		for i in range(1, 6): # Run algorithms five times to get average.
			# Create input file with n elements in range [0, t).
			with open('%s.%s.4.in' % (t, n), 'w') as f:
				f.write(get_output("python genfile.py %s %s" % (t, n)))
			op, time = run_program('dp')
			dp_ops += op
			dp_times += time
			op, time = run_program('naive')
			na_ops += op
			na_times += time
		# Write output results to file.
		with open('output.txt', 'a') as out:
			sys.stdout.write('for %d numbers in 	range (1, %d)\n' %(n, t))
			sys.stdout.write('dp: operations = %f time = %f\n' % (dp_ops / 5.0, dp_times / 5.0))
			sys.stdout.write('na: operations = %f time = %f\n' % (na_ops / 5.0, na_times / 5.0))
			
			out.write('for %d numbers in 	range (1, %d)\n' %(n, t))
			out.write('dp: operations = %f time = %f\n' % (dp_ops / 5.0, dp_times / 5.0))
			out.write('na: operations = %f time = %f\n' % (na_ops / 5.0, na_times / 5.0))