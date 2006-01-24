# $NetBSD: Makefile,v 1.11 2006/01/24 07:32:59 wiz Exp $

DISTNAME=	Gtk2-1.042
PKGNAME=	p5-gtk2-1.042
PKGREVISION=	4
CATEGORIES=	x11 perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtk2-perl/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gtk2-perl.sourceforge.net/
COMMENT=	Perl bindings for GTK+ 2.0

DEPENDS+=	p5-ExtUtils-Depends>=0.2:../../devel/p5-ExtUtils-Depends
DEPENDS+=	p5-ExtUtils-PkgConfig>=1.03:../../devel/p5-ExtUtils-PkgConfig

USE_TOOLS+=	gmake

PERL5_PACKLIST=	auto/Gtk2/.packlist

.include "../../devel/p5-glib2/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
