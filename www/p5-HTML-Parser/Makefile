# $NetBSD: Makefile,v 1.17 2002/09/21 07:48:19 jlam Exp $
#

DISTNAME=		HTML-Parser-3.26
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5hpa
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		jlam@netbsd.org
COMMENT=		perl5 module to parse HTML text documents

DEPENDS+=		p5-HTML-Tagset>=3.0:../../www/p5-HTML-Tagset

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/HTML/Parser/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
