/**
 * @autor <corentin@marciau.fr>
 */

#ifndef _AUTOMATE_H_
#define _AUTOMATE_H_

#define NB_ETAT 4
#define Q1 0
#define Q2 1
#define Q3 2
#define Q4 3
typedef int Etat;

#define NB_ENTREE 5
#define E_DIESE     0           /* caractère : #     */
#define E_DOLLAR    1           /* caractère : $     */
#define E_ANTISLASH 2           /* caractère : \     */
#define E_RETOUR    3           /* caractère : \n    */
#define E_AUTRE     4           /* caractère : autre */
typedef int Entree;

#define S_IDENTITE       0      /* sortie : car      */
#define S_NEANT          1      /* sortie : (néant)  */
typedef int Sortie;

void traiter_fichier (FILE *, FILE *);

#endif
