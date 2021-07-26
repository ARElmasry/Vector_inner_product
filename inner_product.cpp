	#include <vector> 
	#include <iostream>
	#include <iomanip>
	#include <random>
	#include <numeric> 
	#include <fstream>
	
	using DVec = std::vector<double>;
	using DT = DVec::value_type;
	using ST = DVec::size_type;
	using std::transform;
	using std::accumulate;
	using std::sort;
	using std::cout;
	using std::endl;
	using std::setprecision;
	using std::fixed;
	using std::ofstream;
	using std::ios;
class vectorProdcut
{
	
	public:
		DVec v{};
		DVec w{};
		void vectors();
		
	private:
		auto InnerProduct(const DVec&, const DVec &);
};	
	
	
auto vectorProdcut :: InnerProduct(const DVec & v, const DVec & w)
		{
			DVec z; 
			
			transform (v.begin(), v.end(), w.begin(), back_inserter(z),
								 [] (const auto & v_el, const auto & w_el) {return v_el*w_el;});
			sort(z.begin(), z.end(),
					 [] (const DT & p, const DT & q) {return fabs(p) < fabs(q);});
		
			return accumulate (z.begin(), z.end(), DT());
		}
		
void vectorProdcut :: vectors()
		{
			
		ofstream outFile;
		outFile.open("Results.txt", ios::app);
		
		cout << "InnerProduct = \t" << fixed << setprecision(10)
				 << InnerProduct(v, w) << endl;
		outFile << "InnerProduct = \t" << fixed << setprecision(10)
				 << InnerProduct(v, w) << endl;		 
		
		}


int main()
{
	vectorProdcut object;
	/////////////////////////////////////////////
	/////////////////////////////////////////////
	/////////////////////////////////////////////
	/////////////////////////////////////////////
	////////////Enter you vectors Here///////////
	//For Example:///////////////////////////////
	object.v={-10,20,30.0};
	object.w={10,20.50,30};
	/////////////////////////////////////////////
	/////////////////////////////////////////////
	/////////////////////////////////////////////
	/////////////////////////////////////////////
	object.vectors();
	return 0;
}
