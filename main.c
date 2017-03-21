#include <stdio.h>

int data[10] = {4, 2, 8, 5, 10, 9, 7, 1, 6, 3};

//void insertionSort(int [], int nItems);
	
	//function labeling and definition
asm(	"	.text							\n"
	"	.globl	insertionSort					\n"
	"	.type insertionSort,@function				\n"
	//saving stack space
	"insertionSort:							\n"
	"	push	%rbp						\n"
	"	movq	%rsp,%rbp					\n"
	//initialization of variables
	"	xchg	%esi,%eax					\n"
	"	cdqe			/*changes double to quad word*/	\n"
	"	xchg	%rax,%rsi	/*swap rax and rsi*/		\n"
	"	decq	%rsi		/*make nitems - 1 */		\n"	
	"	xorq	%r8,%r8		/*make s = 0	*/		\n"
	"	incq	%r8		/*increm. s = 1	*/		\n"
	"	jmp	4f		/*go to for loop conditions*/	\n"
	//for loop starts here	
	"1:	movl	(%rdi,%r8,4),%eax /*x = L[s]	*/		\n"
	"	movq	%r8,%r10	/*s into i	*/		\n"
	"	decq	%r10		/*make i = s - 1 */		\n"
	"	jmp	3f		/*go to while loop conditions*/	\n"
	//while loop starts here
	"2:	incq	%r10		/*increment i for transfer*/	\n"
	"	movl	%ecx,(%rdi,%r10,4) /*mov tmp to l[i+1]	*/	\n"
	"	subq	$2,%r10		/* subtract two for i-1	*/	\n"
	//while loop conditions
	"3:	movl	(%rdi,%r10,4),%ecx /*make tmp = L[i]*/		\n"
	"	cmpl	%ecx,%eax					\n"
	"	jge	6f		/*if l[i]>x go to next cond.*/	\n"
	"5:	cmpq	$0,%r10		/*compare to zero*/		\n"
	"	jge	2b		/*jump if i < 0	*/		\n"
	//end of while loop, do end of for loop
	"6:	incq	%r10		/*increment i for number load*/	\n"
	"	movl	%eax,(%rdi,%r10,4) /*L[i+1] = x	*/		\n"
	"	decq	%r10		/*make i, i	*/		\n"
	"	incq	%r8		/* make s = s+1	*/		\n"
	//condition for for loop
	"4:	cmpq	%r8,%rsi					\n"
	"	jge	1b						\n"
	//finished, change stack pointer back, pop, and return
	"	movq	%rbp,%rsp					\n"
	"	pop	%rbp						\n"
	"	ret							\n"
	"	.size	insertionSort,.-insertionSort			\n"
	);


int main(void) {

	int data[10] = {4, 2, 8, 5, 10, 9, 7, 1, 6, 3};

	int nItems = 10;
	int i = 0;
	insertionSort(data,nItems);

	for(i;i<nItems;i++) printf("%i\n", data[i]);

}
