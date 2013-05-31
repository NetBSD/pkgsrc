# $NetBSD: Makefile,v 1.32 2013/05/31 12:42:40 wiz Exp $
#

DISTNAME=	FCGI-0.74
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
SVR4_PKGNAME=	p5fcg
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=FCGI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fastcgi.com/
COMMENT=	Perl5 library for FastCGI, a fast startup alternative to CGI

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/FCGI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
