# $NetBSD: Makefile,v 1.2 2001/11/26 06:50:36 jlam Exp $

DISTNAME=		HTML-TableExtract-1.06
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		damon@netbsd.org
HOMEPAGE=		http://sourceforge.net/projects/table-extract/
COMMENT=		perl5 module to simplify extracting HTML tables

DEPENDS+=		p5-HTML-Parser>=3.08:../../www/p5-HTML-Parser

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/HTML-TableExtract/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
