# $NetBSD: Makefile,v 1.6 1999/04/12 17:57:23 hubertf Exp $
#

DISTNAME=		Gtk-0.5120
PKGNAME=		p5-gtk-0.5120
CATEGORIES=		x11 perl5
MASTER_SITES=		ftp://ftp.gtk.org/pub/gtk/perl/

MAINTAINER=		root@garbled.net

DEPENDS+=		gtk+-1.2.0:../../x11/gtk

USE_PERL5=		yes

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
