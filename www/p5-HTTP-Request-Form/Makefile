# $NetBSD: Makefile,v 1.9 2004/04/27 05:44:23 snj Exp $
#

DISTNAME=	HTTP-Request-Form-0.7
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
SVR4_PKGNAME=	p5htt
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Construct HTTP::Request objects for form processing

DEPENDS+=       p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=       p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=       p5-HTML-Tagset-[0-9]*:../../www/p5-HTML-Tagset
DEPENDS+=       p5-HTML-Tree-[0-9]*:../../www/p5-HTML-Tree

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/HTTP/Request/Form/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
