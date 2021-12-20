#ifndef SHOP_INTEGRATED_H
#define SHOP_INTEGRATED_H

// This file contains functions, which were taken from another "HTML Generator" project.

/*              Dokumentacija
 * Paskirtis: kurti "Apie mane" tipo internetini puslapi
 * Autoriai: Eigirdas Stancius, Nojus Blaziunas
 * Versija: 1.0 (2021 - 12 - 12)
 */

// visur funkcijose, kur validacija, grazina 0, jei blogai, 1 - gerai

// turi buti tik raides
int validate_name_OR_surname(char name[]);
// turi buti tik skaiciai arba pradzioje gali buti "+"
int validate_phone_number(char phone_number[]);
// turi buti formalus elektroninio pasto formatas
int validate_email(char email[]);

#endif