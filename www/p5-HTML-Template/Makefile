# $NetBSD: Makefile,v 1.7 2002/08/31 01:34:23 wiz Exp $

DISTNAME=		HTML-Template-2.6
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5htm
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/} \
			${MASTER_SITE_SOURCEFORGE:=html-template/}

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://html-template.sourceforge.net/
COMMENT=		perl5 module to create HTML templates by extending HTML with simple tags

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/HTML/Template/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
