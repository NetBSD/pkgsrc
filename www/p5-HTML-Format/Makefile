# $NetBSD: Makefile,v 1.3 2001/10/18 15:20:49 veego Exp $

DISTNAME=		HTML-Format-1.23
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5hfo
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		packages@netbsd.org
COMMENT=		perl5 modules for converting HTML to other text formats

DEPENDS+=		p5-Font-AFM>=1.18:../../print/p5-Font-AFM
DEPENDS+=		p5-HTML-Tree>=3.04:../../www/p5-HTML-Tree

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/HTML-Format/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
