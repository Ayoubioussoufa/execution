/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:40:06 by aybiouss          #+#    #+#             */
/*   Updated: 2023/02/16 14:52:21 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int	export_builtin(char **cmd)
{
	//khass n initializi env in main and start using it everywhere it needs to be;
    //env init and creat
    //then in unset, i give it that struct olkhdma at3awd mmn lwl OR w9tma nssali ghadi nfreei on3mr struct b akhir env dyali, that might be a good idea
    // f export anchd ayi variable tcreat + aykoun dakchi msorti b ordre alphabetique bl env
    // f env ila kant chi haja bla = maghatktbch wlk
    // li fiha = bo7dha, f export katktb x="" , env katktb ghir x=
    // declare -x in bash f lwl dyal ayi jomla f export.
}
//les cas li f export :
//export bo7dha
//export b variable deja kayna  || makaynach
//variable fiha = wla la ""flag""
//export b vraiable makayna
// export katdefini variable b = dyalha

//environment khdam fih f cd, unset, export !!!!!!! needs to be changed there