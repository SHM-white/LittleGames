using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SmartestMan_C_Test
{
    public class Question
    {
        public string question;
        public string[] answers;
        public int correctAnswer;

        public Question(string question, string[] answers, int correctAnswer)
        {
            this.question = question;
            this.answers = answers;
            this.correctAnswer = correctAnswer;
        }

        public static List<Question> LoadQuestions(string fileName)
        {
            List<Question> questions = new List<Question>();
            using (StreamReader reader = new StreamReader(fileName, Encoding.UTF8))
            {
                while (!reader.EndOfStream)
                {
                    string line = reader.ReadLine();
                    if (!string.IsNullOrEmpty(line))
                    {
                        string[] parts = line.Split('|');
                        if (parts.Length == 6)
                        {
                            string question = parts[0];
                            string[] answers = new string[4];
                            for (int i = 0; i < 4; i++)
                            {
                                answers[i] = parts[i + 1];
                            }
                            int correctAnswer = int.Parse(parts[5]);
                            questions.Add(new Question(question, answers, correctAnswer));
                        }
                    }
                }
            }
            return questions;
        }

        public override string ToString()
        {
            StringBuilder sb = new StringBuilder();
            sb.AppendLine(this.question);
            for (int i = 0; i < 4; i++)
            {
                sb.AppendLine((i + 1) + ". " + this.answers[i]);
            }
            return sb.ToString();
        }
    }
}
