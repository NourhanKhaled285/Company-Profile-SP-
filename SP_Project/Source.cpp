
#include <iostream>

#include <string>

#include <conio.h >

using namespace std;


struct project {

	int ID;
	string title;
	string tit2;
	string breif;
	string breif2;


	int s_day;
	int s_month;
	int s_year;

	int e_day;
	int e_month;
	int e_year;


};

struct newss {


	int day;
	int month;
	int year;

	project p;



};



void list_of_projects(project* a_p, int no_projects);            /* the decleration of the fn listing the array of projects  */


void input_projects(project* a_p, int no_projects);                       /*  the decleration of the fn input the array of projects */

void input_news(newss* news, int no_news);

void listing_all_news(newss* news, int no_news, project* a_p, int no_projects);

void list_all_projects(project* a_p, int no_projects);



void main() {


	string name1;                                      /* making a  username and password to show the information of projects */


	string name2;

	cout << "please enter the user name " << endl;


	cin >> name1;

	getline(cin, name2);

	string name3 = name1 + name2;





	char ch;                                                                     /*making a password*/


	bool isspecial = false, isnum = false;




	cout << endl;

	cout << " Enter Password:" << endl << endl;                     /*passwoard should contain at least one special character from this $,%,_,#,@ */



	while (true)
	{
		ch = _getch();

		if (ch == '\r')
		{
			break;
		}
		if (ch == '$' || ch == '%' || ch == '_' || ch == '#' || ch == '@')
		{
			isspecial = true;
		}
		if (ch >= 48 && ch <= 57)
		{
			isnum = true;
		}
	}
	if (isspecial == false)

		cout << endl << "Password is not valid" << endl;







	else if (isspecial == true) {                        /* if the password is valid then will be show the information or the projects */



		int size;

		cout << "please enter the number of projects to create them" << endl;

		cin >> size;

		project* a_p = new project[size];                      /* decleration of dynamic array of projects*/











		list_of_projects(a_p, size);                          /* calling the function of listing project to display it */


		input_projects(a_p, size);

		/* calling of the input function to enter the information   */

		list_all_projects(a_p, size);

		cout << endl;

		a_p[0].ID = 10;


		for (int i = 0; i < size; i++) {

			/* making the ID of projects where start with initial value

			  and the tresst of them incrementing by the counter

				  assuming that value is (10) or any value */
			a_p[i + 1].ID = a_p[i].ID + 1;


		}




		cout << "please enter the first date or end date for filtration of the projects " << endl;

		/* filtering all projects

	  by user enter first or end date to filter them */

		int d, m, y;

		cin >> d >> m >> y;
		cout << endl;


		cout << "the filtering projects" << endl;


		for (int i = 0; i < size; i++) {



			if (d == a_p[i].s_day || d == a_p[i].e_day) {

				if (m == a_p[i].s_month || m == a_p[i].e_month) {

					if (y == a_p[i].s_year || y == a_p[i].e_year) {



						cout << "the ID of the remaining project  " << i + 1 << " : " << a_p[i].ID << endl;


						cout << "the title of the remaining project " << i + 1 << " : " << a_p[i].title << endl;

						cout << "the breif of the remaining project " << i + 1 << " : " << a_p[i].breif << endl;

					}
				}
			}
		}

		cout << endl;







		newss* news = new newss[size];

		cout << "please create news for each project " << endl;

		input_news(news, size);

		listing_all_news(news, size, a_p, size);


		cout << endl;

		cout << "please select the ID of the project and enter the title to filtering news" << endl;

		cout << "**************************************************************************" << endl;


		for (int i = 0; i < size; i++) {

			cout << "the ID of the remaining project  " << i + 1 << " : " << a_p[i].ID << endl;

			cout << "the title of the remaining project " << i + 1 << " : " << a_p[i].title << endl;
		}

		cout << endl;



		char t[100];

		int id;


		a_p[0].ID = 10;


		for (int i = 0; i < size; i++) {


			a_p[i + 1].ID = a_p[i].ID + 1;


		}


		cout << "please select the Project ID to filter the list of news " << endl;

		cout << "**********************************************************" << endl;

		cin >> id;

		for (int i = 0; i < size; i++) {

			if (id == a_p[i].ID) {



				cout << "the title of news of project " << i + 1 << " : " << news[i].p.title << endl;

				cout << "the brief of news of project " << i + 1 << " : " << news[i].p.breif << endl;


				cout << "the publshing date  of news of project " << i + 1 << " : " << news[i].day << " / " << news[i].month << " / " << news[i].year << endl;

			}

		}

		cout << endl;

		//cout << "enter the title to filter projects " << endl;

		//cout << "************************************" << endl;


		//cin >> t;



		//for (int i = 0; i < size; i++) {

		//	if (t == a_p[i].title) {


		//		list_all_projects(a_p, size);


		//	}

		//}

		cout << "By Nourhan Khalid" << endl;

		cout << "Thank You ^^ " << endl;


		/*delete[] a_p;
		delete[] news;*/


	}


}






void list_of_projects(project* a_p, int no_projects) {            /* the difination of the functon of listing projects


																 the actual implementation of the function to list projects */



	for (int i = 0; i < no_projects; i++) {

		cout << " the project " << i + 1 << endl;
	}


}






void input_projects(project* a_p, int no_projects) {
	/* the difination of the functon of entering information oprojects


the actual implementation of the function to enter the details of projects */



	for (int i = 0; i < no_projects; i++) {

		string tit_temp;
		string breif_temp;


		cout << "please enter the title of the project " << i + 1 << endl;
	
		cin >> tit_temp;

		getline(cin, a_p[i].tit2);

		a_p[i].title =  tit_temp+ a_p[i].tit2;

		cout << "please enter the breif of the project " << i + 1 << endl;

		cin >> breif_temp;

		getline(cin, a_p[i].breif2);

		a_p[i].breif = breif_temp + a_p[i].breif2;
		cout << "please enter the first date  of the project " << i + 1 << endl;

		cin >> a_p[i].s_day >> a_p[i].s_month >> a_p[i].s_year;

		cout << "please enter the last date of the project " << i + 1 << endl;

		cin >> a_p[i].e_day >> a_p[i].e_month >> a_p[i].e_year;

		cout << endl << endl;


	}


}



void list_all_projects(project* a_p, int no_projects) {

	a_p[0].ID = 10;


	for (int i = 0; i < no_projects; i++) {






		a_p[i + 1].ID = a_p[i].ID + 1;


	}



	for (int i = 0; i < no_projects; i++) {


		cout << "the ID of the project " << i + 1 << " : " << a_p[i].ID << endl;



		cout << "the title of the project " << i + 1 << " : " << a_p[i].title << endl;



		cout << "the breif of the project " << i + 1 << " : " << a_p[i].breif << endl;



		cout << "the start date of the project " << i + 1 << " : " << a_p[i].s_day << " / " << a_p[i].s_month << " / " << a_p[i].s_year << endl;



		cout << "the end date of project " << i + 1 << " : " << a_p[i].e_day << " / " << a_p[i].e_month << " / " << a_p[i].e_year << endl;

		cout << endl;


	}

	cout << endl;

}








void input_news(newss* news, int no_news) {







	for (int i = 0; i < no_news; i++) {

		string tit_temp;
		string breif_temp;


		cout << "please enter the title of the  news of the project  " << i + 1 << endl;

		cin >> tit_temp;

		getline(cin, news[i].p.tit2);

		news[i].p.title = tit_temp + news[i].p.tit2;


		cout << "please enter the breif of the news of the project " << i + 1 << endl;

		cin >> breif_temp;

		getline(cin, news[i].p.breif2);

		news[i].p.breif = breif_temp + news[i].p.breif2;

		cout << "please enter the publshing date of the news of the project " << i + 1 << endl;


		cin >> news[i].day >> news[i].month >> news[i].year;





	}

}


void listing_all_news(newss* news, int no_news, project* a_p, int no_projects)

{




	for (int i = 0; i < no_news; i++) {


		cout << "the title of news of project " << i + 1 << " : " << news[i].p.title << endl;


		cout << " and the title of the project " << i + 1 << " is " << a_p[i].title << endl;


		cout << "the brief of news of project " << i + 1 << " : " << news[i].p.breif << endl;


		cout << "the publshing date  of news of project " << i + 1 << " : " << news[i].day << " / " << news[i].month << " / " << news[i].year << endl;

		cout << endl;
	}


	cout << endl;
}
