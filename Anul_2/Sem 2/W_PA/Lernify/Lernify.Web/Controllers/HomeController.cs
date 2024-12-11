using Lernify.BusinessLogic.Interfaces;
using Lernify.Domain.Entities.User;
using System.Web.Mvc;

namespace Lernify.Web.Controllers
{
     public class HomeController : BaseController
     {
          // GET: Home
          public ActionResult Index()
          {
               SessionStatus();
               return View();
          }
     }
}