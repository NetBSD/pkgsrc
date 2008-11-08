# $NetBSD: Makefile,v 1.1.1.1 2008/11/08 09:43:57 wiz Exp $
#

DISTNAME=		CGI-Lite-2.02
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5cgl
PKGREVISION=		2
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		bad@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/CGI-Lite/
COMMENT=		Simple perl5 module for writing forms-based CGI programs

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/CGI/Lite/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
