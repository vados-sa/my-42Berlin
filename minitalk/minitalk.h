/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:01:34 by vados-sa          #+#    #+#             */
/*   Updated: 2024/03/08 13:59:54 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

struct sigaction {
    void     (*sa_handler)(int);
    //void     (*sa_sigaction)(int, siginfo_t *, void *);
    //sigset_t   sa_mask;
    int        sa_flags;
    void     (*sa_restorer)(void);
};
