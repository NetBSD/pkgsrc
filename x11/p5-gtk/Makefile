# $NetBSD: Makefile,v 1.12 2000/08/27 07:11:26 jlam Exp $
#

DISTNAME=		Gtk-0.5120
PKGNAME=		p5-gtk-0.5120
CATEGORIES=		x11 perl5
MASTER_SITES=		ftp://ftp.gtk.org/pub/gtk/perl/

MAINTAINER=		root@garbled.net

DEPENDS+=		gtk+-1.2.*:../../x11/gtk

USE_X11=		# defined
USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Gtk/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
