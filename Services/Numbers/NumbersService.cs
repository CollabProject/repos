using Domain.ViewModels;

namespace Services.Numbers
{
    public class NumbersService : INumbersService
    {
        public NumbersService()
        {

        }

        public void DisplayNumbers(DisplayNumbersModel model)
        {
            // if its less than or equal to 0 default to 1 else take the input
            var startNumber = model.StartNumber <= 0 ? 1 : model.StartNumber;

            // if its less than or equal to 0 default to 100 else take input
            var endNumber = model.EndNumber <= 0 ? 100 : model.EndNumber;

            for (int i = startNumber; i <= endNumber; i++)
            {
                // if multiple of both 5 and 3, display Eurofins
                if (i % 5 == 0 && i % 3 == 0)
                {
                    model.NumbersToDisplay.Add("Eurofins");
                }
                // if multiple of 3, display Three
                else if (i % 3 == 0)
                {
                    model.NumbersToDisplay.Add("Three");
                }
                // if multiple of 5, display Five
                else if (i % 5 == 0)
                {
                    model.NumbersToDisplay.Add("Five");
                }
                // Else display index value
                else
                {
                    model.NumbersToDisplay.Add(i.ToString());
                }
            }
        }
    }
}