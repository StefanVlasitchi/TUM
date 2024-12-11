using System.Web.Mvc;
using Learnify.Web.Models;

namespace Learnify.Web.Controllers
{
     public class HomeController : Controller
     {
          // GET: Home
          public ActionResult Index()
          {
               UserData u = new UserData();
               u.Username = "Customer";

               return View();
          }
     }
}