# $NetBSD: Makefile,v 1.4 2001/11/26 06:50:34 jlam Exp $

DISTNAME=		HTML-Format-1.23
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5hfo
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		packages@netbsd.org
COMMENT=		perl5 modules for converting HTML to other text formats

DEPENDS+=		p5-Font-AFM>=1.18:../../print/p5-Font-AFM
DEPENDS+=		p5-HTML-Tree>=3.04:../../www/p5-HTML-Tree

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/HTML-Format/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
