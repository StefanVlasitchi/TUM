﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Learnify.BusinessLogic.Interfaces;

namespace Learnify.BusinessLogic
{
     public class BussinesLogic
     {
          public ISession GetSessionBL()
          {
               return new SessionBL();
          }
     }
}
