import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class VisitCounterServlet extends HttpServlet {

    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {

        response.setContentType("text/html");
        PrintWriter out = response.getWriter();

        int visitCount = 1;
        Cookie[] cookies = request.getCookies();

        if (cookies != null) {
            for (Cookie cookie : cookies) {
                if (cookie.getName().equals("visitCount")) {
                    visitCount = Integer.parseInt(cookie.getValue()) + 1;
                    break;
                }
            }
        }

        Cookie visitCookie = new Cookie("visitCount", Integer.toString(visitCount));
        visitCookie.setMaxAge(60 * 60 * 24 * 365); // 1 year
        response.addCookie(visitCookie);

        out.println("<h2>Welcome! You have visited this page " + visitCount + " times.</h2>");
        out.close();
    }
}
