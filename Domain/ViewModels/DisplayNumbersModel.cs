using System.Collections.Generic;

namespace Domain.ViewModels
{
    public class DisplayNumbersModel
    {
        public DisplayNumbersModel()
        {
            NumbersToDisplay = new List<string>();
        }

        public int StartNumber { get; set; }

        public int EndNumber { get; set; }

        public List<string> NumbersToDisplay { get; set; }
    }
}