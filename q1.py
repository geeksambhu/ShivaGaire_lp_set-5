'''
  Author  : Shiva Gaire
  email   : geeksambhu@gmail.com
  License : MIT

  This code is compiled with python3.5
'''


import re 
import unittest
def find(test_str):
    #test_str = "101010101010123456789999999999"
    matches = re.finditer(r'(?=(\d{13}))',test_str)
    results = [match.group(1) for match in matches]
    greatest=1

    adjacent_digits=""
    for num in results:
        product=1
        for i in range (13):
            product=product*int(num[0])
        if product > greatest:
            greatest        =  product
            adjacent_digits =  num
    #print("The 13 adjacent digits with highest product are "+adjacent_digits+"and product is: "+str(greatest))
    return greatest,adjacent_digits
  
  
class TestMethods(unittest.TestCase):

    def test1(self):
        number,pattern= find("123456789999999999999")
        self.assertEqual(number,9**13)
        self.assertEqual(pattern,"9"*13 )    
    
    def test2(self):
        self.assertEqual(find("10101010101010101022222222222222222010101"),(2**13, "2"*13))
        
    def test3(self):
        self.assertEqual(find("1111111111111110222222222222223099999999999999"),(9**13, "9"*13) )

    def test4(self):
        string="1010100101010101010101010101010101010101010101010999999999999988888888888811111010101"
        number, pattern = find(string)
        self.assertEqual((number,pattern),  (9**13, "9"*13))
     
if __name__ == '__main__':
    unittest.main() 
