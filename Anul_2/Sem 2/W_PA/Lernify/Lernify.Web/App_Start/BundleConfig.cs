using System.Web.Optimization;

namespace Lernify.Web
{
     public static class BundleConfig
     {
          public static void RegisterBundles(BundleCollection bundles)
          {
               bundles.Add(new StyleBundle("~/bundles/animate/css").Include(
                    "~/assets/css/animate.min.css", new CssRewriteUrlTransform()));
               bundles.Add(new StyleBundle("~/bundles/backToTop/css").Include(
                    "~/assets/css/backToTop.css", new CssRewriteUrlTransform()));
               bundles.Add(new StyleBundle("~/bundles/bootstrap/css").Include(
                    "~/assets/css/bootstrap.min.css", new CssRewriteUrlTransform()));
               bundles.Add(new StyleBundle("~/bundles/default/css").Include(
                    "~/assets/css/default.css", new CssRewriteUrlTransform()));
               bundles.Add(new StyleBundle("~/bundles/elegantFont/css").Include(
                    "~/assets/css/elegantFont.css", new CssRewriteUrlTransform()));
               bundles.Add(new StyleBundle("~/bundles/fontAwesome5Pro/css").Include(
                    "~/assets/css/fontAwesome5Pro.css", new CssRewriteUrlTransform()));
               bundles.Add(new StyleBundle("~/bundles/jquery.fancybox/css").Include(
                    "~/assets/css/jquery.fancybox.min.css", new CssRewriteUrlTransform()));
               bundles.Add(new StyleBundle("~/bundles/meanmenu/css").Include(
                    "~/assets/css/meanmenu.css", new CssRewriteUrlTransform()));
               bundles.Add(new StyleBundle("~/bundles/owl.carousel/css").Include(
                    "~/assets/css/owl.carousel.min.css", new CssRewriteUrlTransform()));
               bundles.Add(new StyleBundle("~/bundles/preloader/css").Include(
                    "~/assets/css/preloader.css", new CssRewriteUrlTransform()));
               bundles.Add(new StyleBundle("~/bundles/style/css").Include(
                    "~/assets/css/style.css", new CssRewriteUrlTransform()));
               bundles.Add(new StyleBundle("~/bundles/swiper-bundle/css").Include(
                    "~/assets/css/swiper-bundle.css", new CssRewriteUrlTransform()));
               bundles.Add(new StyleBundle("~/bundles/new-bundle/css").Include(
                    "~/assets/css/new-bundle.css", new CssRewriteUrlTransform()));


               bundles.Add(new ScriptBundle("~/bundles/jquery-3.5.1/js").Include(
                    "~/assets/js/vendor/jquery-3.5.1.min.js", new CssRewriteUrlTransform()));
               bundles.Add(new ScriptBundle("~/bundles/waypoints/js").Include(
                    "~/assets/js/vendor/waypoints.min.js", new CssRewriteUrlTransform()));
               bundles.Add(new ScriptBundle("~/bundles/backtotop/js").Include(
                    "~/assets/js/vendor/backtotop.min.js", new CssRewriteUrlTransform()));
               bundles.Add(new ScriptBundle("~/bundles/ajax-form/js").Include(
                    "~/assets/js/ajax-form.js", new CssRewriteUrlTransform()));
               bundles.Add(new ScriptBundle("~/bundles/backToTop/js").Include(
                    "~/assets/js/backToTop.js", new CssRewriteUrlTransform()));
               bundles.Add(new ScriptBundle("~/bundles/bootstrap.bundle/js").Include(
                    "~/assets/js/bootstrap.bundle.min.js", new CssRewriteUrlTransform()));
               bundles.Add(new ScriptBundle("~/bundles/imagesloaded.pkgd/js").Include(
                    "~/assets/js/imagesloaded.pkgd.min.js", new CssRewriteUrlTransform()));
               bundles.Add(new ScriptBundle("~/bundles/isotope.pkgd/js").Include(
                    "~/assets/js/isotope.pkgd.min.js", new CssRewriteUrlTransform()));
               bundles.Add(new ScriptBundle("~/bundles/jquery.fancybox/js").Include(
                    "~/assets/js/jquery.fancybox.min.js", new CssRewriteUrlTransform()));
               bundles.Add(new ScriptBundle("~/bundles/jquery.meanmenu/js").Include(
                    "~/assets/js/jquery.meanmenu.js", new CssRewriteUrlTransform()));
               bundles.Add(new ScriptBundle("~/bundles/main/js").Include(
                    "~/assets/js/main.js", new CssRewriteUrlTransform()));
               bundles.Add(new ScriptBundle("~/bundles/owl.carousel/js").Include(
                    "~/assets/js/owl.carousel.min.js", new CssRewriteUrlTransform()));
               bundles.Add(new ScriptBundle("~/bundles/parallax/js").Include(
                    "~/assets/js/parallax.min.js", new CssRewriteUrlTransform()));
               bundles.Add(new ScriptBundle("~/bundles/purecounter/js").Include(
                    "~/assets/js/purecounter.js", new CssRewriteUrlTransform()));
               bundles.Add(new ScriptBundle("~/bundles/swiper-bundle/js").Include(
                    "~/assets/js/swiper-bundle.min.js", new CssRewriteUrlTransform()));
               bundles.Add(new ScriptBundle("~/bundles/wow/js").Include(
                    "~/assets/js/wow.min.js", new CssRewriteUrlTransform()));

          }
     }
}