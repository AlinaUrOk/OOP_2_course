using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Media;

namespace Project
{
    public partial class Form1 : Form
    {
        SoundPlayer sound = new SoundPlayer(Properties.Resources.music);
        SoundPlayer sound1 = new SoundPlayer(Properties.Resources.music1);
        SoundPlayer sound2 = new SoundPlayer(Properties.Resources.music2);

        bool goup, godown, goright, goleft, isGameOver;

        int score, playerSpeed, redGhostSpeed, yellowGhostSpeed, pinkGhostX, pinkGhostY;

        public Form1()
        {
            InitializeComponent();

            resetGame();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void keyisdown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Up)
            {
                goup = true;
            }
            if (e.KeyCode == Keys.Down)
            {
                godown = true;
            }
            if (e.KeyCode == Keys.Left)
            {
                goleft = true;
            }
            if (e.KeyCode == Keys.Right)
            {
                goright = true;
            }
        }

        private void keyisup(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Up)
            {
                goup = false;
            }
            if (e.KeyCode == Keys.Down)
            {
                godown = false;
            }
            if (e.KeyCode == Keys.Left)
            {
                goleft = false;
            }
            if (e.KeyCode == Keys.Right)
            {
                goright = false;
            }

            if(e.KeyCode==Keys.Enter && isGameOver == true)
            {
                resetGame();
            }
        }

        private void mainGameTimer(object sender, EventArgs e)
        {
            txtScore.Text = "Score: " + score;
            if (goleft == true)
            {
                packman.Left -= playerSpeed;
                packman.Image = Properties.Resources.left;
            }
            if (goright == true)
            {
                packman.Left += playerSpeed;
                packman.Image = Properties.Resources.right;
            }
            if (godown == true)
            {
                packman.Top += playerSpeed;
                packman.Image = Properties.Resources.down;
            }
            if (goup == true)
            {
                packman.Top -= playerSpeed;
                packman.Image = Properties.Resources.Up;
            }

            if(packman.Left<-10)
            {
                packman.Left = 680;
            }
            if (packman.Left >680)
            {
                packman.Left =-10;
            }
            
            if(packman.Top<-10)
            {
                packman.Top = 550;
            }
            if (packman.Top >550)
            {
                packman.Top =0;
            }

            foreach(Control x in this.Controls)
            {
                if ((string)x.Tag == "coin" && x.Visible == true)
                {
                    if(packman.Bounds.IntersectsWith(x.Bounds))
                    {
                        score += 1;
                        x.Visible = false;
                    }
                }

                if((string)x.Tag=="wall")
                {
                    if (packman.Bounds.IntersectsWith(x.Bounds))
                    {
                        gameOver("You lose!");
                        sound2.Play();
                    }

                    if(PinkGhost.Bounds.IntersectsWith(x.Bounds))
                    {
                        pinkGhostX = -pinkGhostX;
                    }
                }

                if((string)x.Tag == "ghost")
                {
                    if (packman.Bounds.IntersectsWith(x.Bounds))
                    {
                        gameOver("You lose!");
                        sound2.Play();
                    }
                }
            }

            //moving ghost

            RedGhost.Left += redGhostSpeed;

            if((RedGhost.Bounds.IntersectsWith(pictureBox1.Bounds)) || RedGhost.Bounds.IntersectsWith(pictureBox2.Bounds))
            {
                redGhostSpeed = -redGhostSpeed;
            }

            YellowGhost.Left -= yellowGhostSpeed;

            if ((YellowGhost.Bounds.IntersectsWith(pictureBox3.Bounds)) || YellowGhost.Bounds.IntersectsWith(pictureBox4.Bounds))
            {
                yellowGhostSpeed = -yellowGhostSpeed;
            }

            PinkGhost.Left -= pinkGhostX;
            PinkGhost.Top -= pinkGhostY;

            if(PinkGhost.Top < 0 || PinkGhost.Top > 400)
            {
                pinkGhostY = -pinkGhostY;
            }
            if (PinkGhost.Left < 0 || PinkGhost.Left > 400)
            {
                pinkGhostX = -pinkGhostX;
            }


                if (score==46)
            {
                gameOver("You win!");
                sound1.Play();
            }
        }

        private void resetGame()
        {
            sound.Play();
            txtScore.Text = "Score: 0";
            score = 0;

            redGhostSpeed = 5;
            yellowGhostSpeed = 5;
            pinkGhostX = 5;
            pinkGhostY = 5;
            playerSpeed = 8;

            isGameOver = false;
            packman.Left = 31;
            packman.Top = 46;

            RedGhost.Left = 182;
            RedGhost.Top = 64;

            YellowGhost.Left = 270;
            YellowGhost.Top = 350;

            PinkGhost.Left = 400;
            PinkGhost.Top = 183;

            foreach (Control x in this.Controls)
            {
                if (x is PictureBox)
                {
                    x.Visible = true;
                }
            }

            gimeTimer.Start();
        }

        private void gameOver(string message)
        {
            isGameOver = true;
            sound.Stop();
            gimeTimer.Stop();

            txtScore.Text += Environment.NewLine + message;
        }
    }
}
