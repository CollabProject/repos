using Domain.ViewModels;
using Services.Numbers;
using System.Web.Mvc;

namespace EurofinsCodingChallenge.Controllers
{
    public class HomeController : Controller
    {
        private readonly INumbersService numberService;

        public HomeController()
        {
            this.numberService = (INumbersService)DependencyResolver.Current.GetService(typeof(INumbersService));
        }

        [HttpGet]
        public ActionResult Index()
        {
            DisplayNumbersModel viewModel = new DisplayNumbersModel();
            return View("Index", viewModel);
        }

        [HttpPost]
        public ActionResult Index(DisplayNumbersModel model)
        {
            numberService.DisplayNumbers(model);
            return View("Index", model);
        }

        public ActionResult About()
        {
            ViewBag.Message = "This application displays numbers from 1 - 100.";

            return View();
        }
    }
}