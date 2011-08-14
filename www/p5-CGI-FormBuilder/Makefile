# $NetBSD: Makefile,v 1.16 2011/08/14 16:05:45 obache Exp $

DISTNAME=		CGI-FormBuilder-3.0501
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		4
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Perl5 module for building HTML forms
HOMEPAGE=		http://www.formbuilder.org/

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/CGI/FormBuilder/.packlist

DEPENDS+=		p5-HTML-Template>=2.6:../../www/p5-HTML-Template
DEPENDS+=		p5-Text-Template>=1.43:../../textproc/p5-Text-Template
#DEPENDS+=		p5-Template-Toolkit>=2.08:../../www/p5-Template-Toolkit

pre-configure:
	${FIND} ${WRKSRC} -name "*.orig" -type f | ${XARGS} ${RM}

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
