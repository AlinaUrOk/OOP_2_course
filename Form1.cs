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

namespace laba_oop_2
{
    public partial class Form1 : Form
    {
        int hours;
        int minutes;
        int seconds;
        bool IsActive;

        SoundPlayer sound = new SoundPlayer(Properties.Resources.xD);

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            IsActive = false;
        }

        private void btnStart_Click(object sender, EventArgs e)
        {
            IsActive = true;

            hours = Convert.ToInt32(textBox3.Text);
            HR.Text = hours.ToString();

            minutes = Convert.ToInt32(textBox1.Text);
            MIN.Text = minutes.ToString();

            seconds = Convert.ToInt32(textBox2.Text);
            SEC.Text = seconds.ToString();

            //bool b = int.TryParse(label1.Text, out seconds);
            //if (b)
            //{
            //    SEC.Text = seconds.ToString();
            //}

            //timer1.Start();
        }

        private void btnStop_Click(object sender, EventArgs e)
        {
            IsActive = false;
            sound.Stop();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            if (IsActive)
            {
                if (hours == 0 && minutes == 0 && seconds == 0)
                {
                    sound.Play();
                    timer1.Enabled = false;

                }
                if (seconds != 0 )
                {
                    seconds--;
                    SEC.Text = seconds.ToString();
                    if (seconds == 0)
                    {
                        if (minutes != 0)
                        {
                            minutes--;
                            seconds = 59;
                            SEC.Text = seconds.ToString();
                            MIN.Text = minutes.ToString();
                            if (minutes == 0)
                            {
                                if (hours != 0)
                                {
                                    hours--;
                                    minutes = 59;
                                    MIN.Text = minutes.ToString();
                                    seconds = 59;
                                    SEC.Text = seconds.ToString();
                                    HR.Text = hours.ToString();
                                }
                            }
                        }
                    }
                }
                else if (minutes != 0 )
                {
                    minutes--;
                    seconds = 59;
                    SEC.Text = seconds.ToString();
                    MIN.Text = minutes.ToString();
                    if (minutes == 0)
                    {
                        if (hours != 0)
                        {
                            hours--;
                            minutes = 59;
                            MIN.Text = minutes.ToString();
                            HR.Text = hours.ToString();
                        }
                    }
                }
                else if (hours != 0)
                {
                    hours--;
                    minutes = 59;
                    MIN.Text = minutes.ToString();
                    seconds = 59;
                    SEC.Text = seconds.ToString();
                    HR.Text = hours.ToString();
                }



            }
        }


        private void timer2_Tick(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox1_KeyPress(object sender, KeyPressEventArgs e)
        {
            {
                if (!Char.IsDigit(e.KeyChar))
                    e.Handled = true;
            }
        }

        private void textBox2_KeyPress(object sender, KeyPressEventArgs e)
        {
            {
                if (!Char.IsDigit(e.KeyChar))
                    e.Handled = true;
            }
        }

        private void textBox3_KeyPress(object sender, KeyPressEventArgs e)
        {
            {
                if (!Char.IsDigit(e.KeyChar))
                    e.Handled = true;
            }
        }
    }
}
