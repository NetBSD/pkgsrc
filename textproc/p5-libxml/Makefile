# $NetBSD: Makefile,v 1.7 2004/02/22 00:56:58 minskim Exp $

DISTNAME=	libxml-perl-0.07
PKGNAME=	p5-libxml-0.07
SVR4_PKGNAME=	p5lxm
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.bitsko.slc.ut.us/
COMMENT=	Perl module collection for working with XML

DEPENDS+=	p5-XML-Parser>=2.29:../../textproc/p5-XML-Parser

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/libxml-perl/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
