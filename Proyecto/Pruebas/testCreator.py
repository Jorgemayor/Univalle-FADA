import argparse as ap
import random

# Parser
parser = ap.ArgumentParser(prog='testCreator', description='Test creator for Zoo problem')

# Arguments
parser.add_argument('--version', action='version', version='1.0.0')
parser.add_argument('test', help='Name of the test case to create')
parser.add_argument('n', help='Number of animals', type=int)
parser.add_argument('m', help='Number of parts', type=int)
parser.add_argument('k', help='Number of scenes in the m-1 last parts', type=int)

args = parser.parse_args()

# Variables
test_name = args.test + '.txt'
n = args.n
m = args.m
k = args.k

# Validations
if 1 > n:
	print("ERROR: n must be 1 <= n")
	exit(1)

if 2 > m or m > 60:
	print("ERROR: m must be 2 <= m <= 60")
	exit(1)

if 1 > k or k > n:
	print("ERROR: k must be 1 <= k <= n")
	exit(1)

if  k * (m - 1) > n * (n - 1) * (n - 2) / 6:
	print("""Invalid data. There are not enough possible scenes.
Keep in mind the relation: k * (m - 1) <= n * (n - 1) * (n - 2) / 6""")
	exit(1)


animal_names = []
animals_awesomeness = [i for i in range(1, n + 1)]
scenes = set()

# Creates and writes all the animals
with open(test_name, 'w') as file_:
	
	file_.write(str(n) + ' ' + str(m) + ' ' + str(k) + '\n')
	
	for i in range(1, n + 1):
		random_awesomeness = random.choice(animals_awesomeness)
		animals_awesomeness.remove(random_awesomeness)
		animal_name = 'animal' + str(i)
		animal_names.append(animal_name)
		file_.write(animal_name + ' ' + str(random_awesomeness) + '\n')
	
	file_.write('\n')


# Creates all the scenes
while len(scenes) < ((m - 1) * k):

	scene = set()
	while len(scene) < 3:
		scene.add(random.choice(animal_names))
	scenes.add(frozenset(scene))

# Writes all the animals in parts
with open(test_name, 'a') as file_:

	for scene in scenes:
		for animal in scene:
			file_.write(animal + ' ')

		file_.write('\n')

	file_.write('\n')
	
	
	for i in range(m - 1):
		part = set()

		while len(part) < k:
			part.add(random.choice(list(scenes)))

		scenes -= part

		for scene in part:
			for animal in scene:
				file_.write(animal + ' ')

			file_.write('\n')

		file_.write('\n')
			
exit()
