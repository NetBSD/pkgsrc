# $NetBSD: Makefile,v 1.2 2002/10/20 17:46:03 seb Exp $
#

DISTNAME=	XML-Simple-1.08
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5xsi
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Easy Perl API to read/write XML

DEPENDS+=       p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Parser

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/XML/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
