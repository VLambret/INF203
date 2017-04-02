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

#define NB_ENTREE 3
#define E_SLASH  0              /* caractère : /     */
#define E_ETOILE 1              /* caractère : *     */
#define E_AUTRE  2              /* caractère : autre */
typedef int Entree;

#define S_IDENTITE       0      /* sortie : car      */
#define S_SLASH          1      /* sortie : /        */
#define S_SLASH_IDENTITE 2      /* sortie : / + car  */
#define S_NEANT          3      /* sortie : (néant)  */
typedef int Sortie;

void traiter_fichier (FILE *, FILE *);

#endif
