# $NetBSD: Makefile,v 1.6 2003/06/02 01:16:01 jschauma Exp $
#

DISTNAME=	HTTP-Request-Form-0.7
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5htt
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	tech-pkg@netbsd.org
COMMENT=	Construct HTTP::Request objects for form processing

DEPENDS+=       p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=       p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=       p5-HTML-Tagset-[0-9]*:../../www/p5-HTML-Tagset
DEPENDS+=       p5-HTML-Tree-[0-9]*:../../www/p5-HTML-Tree

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/HTTP/Request/Form/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
