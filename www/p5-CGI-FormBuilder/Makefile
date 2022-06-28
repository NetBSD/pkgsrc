# $NetBSD: Makefile,v 1.34 2022/06/28 11:37:11 wiz Exp $

DISTNAME=		CGI-FormBuilder-3.10
PKGNAME=		p5-${DISTNAME}00
PKGREVISION=		6
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Perl5 module for building HTML forms
HOMEPAGE=		http://www.formbuilder.org/
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/CGI/FormBuilder/.packlist

DEPENDS+=		p5-HTML-Template>=2.6:../../www/p5-HTML-Template
DEPENDS+=		p5-Text-Template>=1.43:../../textproc/p5-Text-Template
#DEPENDS+=		p5-Template-Toolkit>=2.08:../../www/p5-Template-Toolkit

# for make test
BUILD_DEPENDS+=		p5-CGI-[0-9]*:../../www/p5-CGI

# Note. Cannot avoid warning from CGI.pm 4.05 or newer by replacing
# $self->{params}->param( with @{$self->{params}->param_fetch
# as breaks usage under Catalyst:
# Can't locate object method "param_fetch" via package "Catalyst::Request"

post-extract:
	${FIND} ${WRKSRC} -name "*.orig" -type f | ${XARGS} ${RM} -f
# garbage in the archive ?
	(cd ${WRKSRC}; ${RM} -rf PaxHeader )

pre-configure:
	${FIND} ${WRKSRC} -name "*.orig" -type f | ${XARGS} ${RM} -f

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
