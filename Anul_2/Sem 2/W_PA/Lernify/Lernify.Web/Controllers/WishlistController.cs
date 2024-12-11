using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Lernify.Web.Controllers
{
    public class WishlistController : BaseController
    {
        // GET: Wishlist
        public ActionResult Index()

        {
             SessionStatus();
            return View();
        }
    }
}