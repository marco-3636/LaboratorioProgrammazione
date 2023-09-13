//
// Created by m36 on 11/09/23.
//
#include <gtest/gtest.h>

#include "../../Note.h"


TEST(Note, DefaultConstructor) {
Note TestNote  = Note("Titolo nota 1", "Testo nota 1", false);
ASSERT_FALSE(" "==TestNote.getText());
ASSERT_FALSE(" "==TestNote.getTitle());
ASSERT_TRUE(TestNote.isLocked()==true || TestNote.isLocked()==false);
}

TEST(Note, GetterAndSetterTester) {
Note TestNote  = Note("Titolo nota 1", "Testo nota 1", false);
TestNote.setTitle("Titolo di Prova");
TestNote.setText("Testo di Prova");
TestNote.setLocked(true);
ASSERT_EQ("Titolo di Prova", TestNote.getTitle());
ASSERT_EQ("Testo di Prova", TestNote.getText());
ASSERT_TRUE(TestNote.isLocked());
}