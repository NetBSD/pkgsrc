# $NetBSD: Makefile,v 1.17 2001/10/18 15:20:53 veego Exp $
#

DISTNAME=		Gtk-Perl-0.7008
PKGNAME=		p5-gtk-0.7008
SVR4_PKGNAME=		p5gtk
WRKSRC=			${WRKDIR}/${DISTNAME}/Gtk
CATEGORIES=		x11 perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Gtk/} \
			ftp://ftp.gtk.org/pub/gtk/perl/

MAINTAINER=		root@garbled.net
COMMENT=		Perl bindings for GTK+

BUILD_DEPENDS+=		p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Writer
BUILD_DEPENDS+=		p5-XML-Writer-[0-9]*:../../textproc/p5-XML-Writer

USE_X11=		YES
USE_PERL5=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Gtk/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL	\
		INSTALLMAN3DIR=${PREFIX}/man/man3

.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
