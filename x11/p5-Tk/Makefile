# $NetBSD: Makefile,v 1.6 1998/04/20 11:56:35 frueauf Exp $
# FreeBSD Id: Makefile,v 1.14 1997/09/14 04:00:00 jfitz Exp
#

DISTNAME=		Tk402.002
PKGNAME=		p5-Tk-402.002
CATEGORIES=		x11 tk80 perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Tk

MAINTAINER=		packages@netbsd.org

BUILD_DEPENDS= 		${PREFIX}/lib/perl5/site_perl/HTML/Parse.pm:${PORTSDIR}/www/p5-libwww
LIB_DEPENDS=		tk80.1.:${PORTSDIR}/x11/tk80

USE_PERL5=		YES

MAN1=			tkweb.1
MAN3=			Bundle::Tk.3 Tk::Adjuster.3 Tk::After.3 \
			Tk::Axis.3 Tk::Balloon.3 Tk::BrowseEntry.3 \
			Tk::CmdLine.3 Tk::ColorEditor.3 Tk::Derived.3 \
			Tk::Dial.3 Tk::DialogBox.3 \
			Tk::DragDrop::Common.3 Tk::DragDrop::SunConst.3 \
			Tk::FileDialog.3 Tk::FileSelect.3 Tk::Font.3 \
			Tk::Ghostscript.3 Tk::HTML::IO.3 Tk::IO.3 \
			Tk::Internals.3 Tk::LabFrame.3 \
			Tk::Menu::Item.3 Tk::NoteBook.3 Tk::OlWm.3 \
			Tk::Parse.3 Tk::ROText.3 Tk::Scrolled.3 \
			Tk::Submethods.3 Tk::Table.3 Tk::Tcl-perl.3 \
			Tk::TextUndo.3 Tk::TiedListbox.3 \
			Tk::UserGuide.3 Tk::WaitBox.3 Tk::X.3 \
			Tk::Xrm.3 Tk::demos::widget_lib::WidgetDemo.3 \
			Tk::pTk.3 Tk::widgets.3 blib.3
MAN3PREFIX=		${PREFIX}/lib/perl5

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
