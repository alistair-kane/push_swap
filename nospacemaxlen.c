#include "push_swap.h"

int	max_run(t_list **head, t_state *state)
{
    t_list  *temp;
    int n;
    int start_len;
    int i;
    int j;
    int len;
    int max;

    temp = *head;
    n = ft_lstsize(temp);
    if (n == 1)
        return (1);
    i = 1;
    while (get_nth_idx(temp, i - 1) < get_nth_idx(temp, i) && i < n)
    {
        start_len++;
        i++;
    }
    max = start_len;
    j = i + 1;
    while (j < n)
    {
        if (get_nth_idx(temp, j - 1) < get_nth_idx(temp, j))
            len++;
        else
        {
            if (max < len)
            {
                max = len;
				state->run_start = j - state->len;
				state->run_end = j;
            }
            len = 1;
        }
    }
    if (get_nth_idx(temp, n - 1) < get_nth_idx(temp, 0))
        len += start_len;
    if (max < len)
        max = len;
	// circular
	if (state->run_end >= n)
		state->run_end = state->run_end - n;
	if (state->run_start >= n)
		state->run_start = state->run_start - n;
	state->len = max;
}
return (state->len);


int longlenCircularSubarr(int arr[], int n)
{
    // if there is only one element
    if (n == 1)
        return 1;
 
    // 'startLen' stores the length of the longest
    // increasing subarray which starts from
    // first element
    int startLen = 1, i;
    int len = 1, max = 0;
 
    // finding the length of the longest
    // increasing subarray starting from
    // first element
    for (i = 1; i < n; i++) {
        if (arr[i - 1] < arr[i])
            startLen++;
        else
            break;
    }
 
    if (max < startLen)
        max = startLen;
 
    // traverse the array index (i+1)
    for (int j = i + 1; j < n; j++) {
 
        // if current element if greater than previous
        // element, then this element helps in building
        // up the previous increasing subarray encountered
        // so far
        if (arr[j - 1] < arr[j])
            len++;
        else {
 
            // check if 'max' length is less than the length
            // of the current increasing subarray. If true,
            // then update 'max'
            if (max < len)
                max = len;
 
            // reset 'len' to 1 as from this element
            // again the length of the new increasing
            // subarray is being calculated
            len = 1;
        }
    }
    // if the last element is less than the first element add the run from idx 0 to current len
    if (arr[n - 1] < arr[0])
        len += startLen;
 
    // update 'max'
    if (max < len)
        max = len;
 
    return max;
}


int	max_run(t_list **head, t_state *state)
{
	t_list	*temp;
	int		temp_len;
	int		i;
	int     n;

    int j;
    int k;

    temp = *head;
	i = 0;
    j = 0;
    k = 1;
    n = ft_lstsize(temp);
	temp_len = 1;
	state->len = 1;
	while (i < (n * 2))
	{
		if (get_nth_idx(temp, j) < get_nth_idx(temp, k))
			temp_len++;
		else
		{
			if (state->len <= temp_len)
			{
				state->len = temp_len;
				state->run_start = i - state->len + 1;
				state->run_end = i;
			}
			temp_len = 1;
		}
		if (k == n)
			k = 0;
		if (j == n)
			j = 1;
		i++;
        j++;
        k++;
	}
	// circular
	if (state->run_end >= ft_lstsize(*head))
		state->run_end = state->run_end - ft_lstsize(*head);
	if (state->run_start >= ft_lstsize(*head))
		state->run_start = state->run_start - ft_lstsize(*head);
	// printf("Lower idx:%d | Upper idx:%d\n", state->run_start, state->run_end); 	// printf("\nLen: %d\n", state->len);
	// printf("Run lower:%d | Run upper:%d", get_nth(*head, state->run_start), get_nth(*head, state->run_end));
	// printf("\nLen: %d\n", state->len);
	return (state->len);
}