# $NetBSD: Makefile,v 1.21 2003/05/05 19:05:26 jmmv Exp $
#

DISTNAME=		Gtk-Perl-0.7008
PKGNAME=		p5-gtk-0.7008
PKGREVISION=		1
SVR4_PKGNAME=		p5gtk
WRKSRC=			${WRKDIR}/${DISTNAME}/Gtk
CATEGORIES=		x11 perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Gtk/} \
			ftp://ftp.gtk.org/pub/gtk/perl/

MAINTAINER=		root@garbled.net
COMMENT=		Perl bindings for GTK+

BUILD_DEPENDS+=		p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Writer
BUILD_DEPENDS+=		p5-XML-Writer-[0-9]*:../../textproc/p5-XML-Writer

USE_BUILDLINK2=		YES
USE_X11=		YES
MAKE_PARAMS=		INSTALLMAN3DIR=${PREFIX}/man/man3
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Gtk/.packlist

.include "../../lang/perl5/module.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
