# $NetBSD: Makefile,v 1.3 2001/10/18 15:20:51 veego Exp $
#

DISTNAME=	HTTP-Request-Form-0.7
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5htt
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Construct HTTP::Request objects for form processing

DEPENDS+=       p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=       p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=       p5-HTML-Tagset-[0-9]*:../../www/p5-HTML-Tagset
DEPENDS+=       p5-HTML-Tree-[0-9]*:../../www/p5-HTML-Tree

USE_PERL5=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/HTTP/Request/Form/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
