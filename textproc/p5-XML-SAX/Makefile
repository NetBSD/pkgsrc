# $NetBSD: Makefile,v 1.7 2004/01/05 22:16:25 jlam Exp $

DISTNAME=	XML-SAX-0.12
PKGNAME=	p5-${DISTNAME}
#SVR4_PKGNAME=	
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl interface to the SAX2 XML Parser

DEPENDS+=	p5-XML-NamespaceSupport>=0.03:../../textproc/p5-XML-NamespaceSupport
DEPENDS+=	p5-File-Temp-[0-9]*:../../devel/p5-File-Temp

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/XML/SAX/.packlist
MAKE_ENV+=		PERL5LIB="${PREFIX}/${PERL5_SUB_INSTALLSITELIB}"

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
