# $NetBSD: Makefile,v 1.2 2008/10/19 19:19:15 he Exp $

DISTNAME=	HTTP-Request-AsCGI-0.5
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/C/CH/CHANSEN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTTP-Request-AsCGI/
COMMENT=	Setup a CGI enviroment from a HTTP::Request

DEPENDS+=	p5-Class-Accessor>=0:../../devel/p5-Class-Accessor
DEPENDS+=	p5-libwww>=5.805:../../www/p5-libwww

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/HTTP/Request/AsCGI/.packlist

PKG_DESTDIR_SUPPORT=    user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
