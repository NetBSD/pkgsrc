# $NetBSD: Makefile,v 1.1.1.1 2001/05/03 16:07:19 wiz Exp $
#

DISTNAME=	HTTP-Request-Form-0.7
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Construct HTTP::Request objects for form processing

DEPENDS+=       p5-libwww-*:../../www/p5-libwww
DEPENDS+=       p5-URI-*:../../www/p5-URI
DEPENDS+=       p5-HTML-Tagset-*:../../www/p5-HTML-Tagset
DEPENDS+=       p5-HTML-Tree-*:../../www/p5-HTML-Tree

USE_PERL5=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/HTTP/Request/Form/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
