# $NetBSD: Makefile,v 1.5 2003/07/21 17:27:46 martti Exp $

DISTNAME=	libxml-perl-0.07
PKGNAME=	p5-libxml-0.07
SVR4_PKGNAME=	p5lxm
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	packages@NetBSD.org
HOMEPAGE=	http://www.bitsko.slc.ut.us/
COMMENT=	Perl module collection for working with XML

DEPENDS+=	p5-XML-Parser>=2.29:../../textproc/p5-XML-Parser

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/libxml-perl/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
