#include <stdio.h>
#include <stdlib.h>

struct dept {
	char dept_name[25];
	int dept_no;
};

typedef struct {
	char	name[25];
	int	employee_id;
	struct	dept department;
	struct	home_address *a_ptr;
	double	salary;
} employee_data;

void update(employee_data *p) {
	int n;
	printf("Input the department number: ");
	scanf("%d", &n);
	p->department.dept_no = n;
}

int main() {
	/*employee_data *e;
	e = (employee_data*) malloc (1 * sizeof(employee_data)); //for array change 1 to length of array
	update(&e);
	printf("Department Number: %d\n", e.department.dept_no);*/
	employee_data *e;
	employee_data ed;
	e = &ed;
	update(e);
	printf("Department Number: %d\n", e->department.dept_no);
	printf("Department Number: %d\n", ed.department.dept_no);
	return 0;
}
